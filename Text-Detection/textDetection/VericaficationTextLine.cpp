#include "VericaficationTextLine.h"
#include <tesseract/baseapi.h>
#include <tesseract/strngs.h>
#include <iostream>
#include <fstream>
#include <cmath>  
using namespace std;
using namespace cv;

PolyGroundTruthSet VericaficationTextLine::run(PolyGroundTruthSet& cgts,cv::Mat& rgb)
{
	this->cgts = cgts;
	this->clearInnerBox();
	this->FilterBoxWithPCAandRandomForest(rgb);
	return cgts;

}

 void VericaficationTextLine::FilterBoxWithPCAandRandomForest(cv::Mat& rgb)
 {
	vector<PolyGroundTruth> newset;
	vector<PolyGroundTruth>& sets = this->cgts.sets;
	vector<PolyGroundTruth> tmp;
	int result[1000];
	int used[1000]={0};
	for(int i=0;i<sets.size();++i)
	{
            int comy=100000;int comx=100000;
	    for(int j=0;j<sets.size();++j)
	    {
	       double midx = sets[j].rr.x + sets[j].rr.width/2;
	       double midy = sets[j].rr.y + sets[j].rr.height/2;
	          if(abs(midy-comy)<=10 )
		{
		    if(midx<comx && !used[j]){result[i]=j;comx=midx;}	
		}
		else 
		{
		  if(midy<comy){if(!used[j]){comx=midx;comy=midy;result[i]=j;}}
                  else continue;	
		}
	    }
            used[result[i]]=1;
	} 
		ofstream outfile("./resource/result.txt");
	for(int i = 0; i< sets.size();i++)
	{
		cv::Mat rgb_copy = rgb;cv::Mat cropped;
		double midx = sets[result[i]].rr.x + sets[result[i]].rr.width/2;
		double midy = sets[result[i]].rr.y + sets[result[i]].rr.height/2;
		cv::Size newsize=sets[result[i]].rr.size();
                newsize.height=newsize.height+5;
		newsize.width=newsize.width+10;
		getRectSubPix(rgb_copy, newsize,cv::Point2f(midx,midy),cropped,-1);
		cv::resize(cropped,cropped,Size(200,60));
		//cv::adaptiveThreshold(cropped,cropped,255);
		//cv::adaptiveThreshold(cropped, cropped,   255, 0,   1, 5,   10);     
		//cv::medianBlur(cropped,cropped,3);
		tesseract::TessBaseAPI tess;
		tess.Init(NULL, "eng", tesseract::OEM_DEFAULT);  
                tess.SetPageSegMode(tesseract::PSM_SINGLE_BLOCK);  
		tess.SetImage((uchar*)cropped.data, cropped.size().width, cropped.size().height, cropped.channels(), cropped.step1());
		tess.Recognize(0);
		const char* out = tess.GetUTF8Text();
		if(fb.Keep(cropped)) {newset.push_back(PolyGroundTruth(sets[result[i]].rr));
		//cv::imshow("Final Result",cropped);
		//cv::imwrite( "./resource/grey.jpg",cropped);

		//cv::imshow("image:",cropped);
		outfile<<out<<endl;
		//cout<<out<<endl;
		//system("tesseract ./resource/grey.jpg ./resource/out");
		//cv::waitKey(20);
		//fstream outfile;
		//ifstream infile("./resource/out.txt");
		//outfile.open("./resource/result.txt", fstream::app );
		//char content[10000];
		//while(infile.getline(content,'\n'))
		//{
		//  outfile<<content<<endl;
		//  cout<<content<<endl;
		//}
		//infile.close();
                //outfile.close();		
		//cv::waitKey(20);
		cv::waitKey(20);
		}
	}
		outfile.close();
	sets = newset;
 }

 void VericaficationTextLine::clearInnerBox()
{
	vector<PolyGroundTruth>& sets = this->cgts.sets; 
	vector<int> sign(sets.size(),1);
	for(int i = 0 ;i< sets.size();i++)
	{
		for(int j = 0;j < sets.size();j++)
		{
			if(i == j) continue;
			if(sets[i].rr.area() > sets[j].rr.area()) continue;

			cv::Rect rec = sets[i].rr & sets[j].rr;
			double theriod = double(sets[i].rr.area()) *0.9;
			if(rec.area() >=theriod) 
			{	sign[i] = 0; break;}
		}
	}
	
	vector<PolyGroundTruth> repalce;
	for(int i = 0; i< sets.size();i++)
		if(sign[i] != 0) repalce.push_back(sets[i]);
	sets = repalce;
}

# -*- coding:utf-8 -*-
import sys  
reload(sys)  
sys.setdefaultencoding("utf8") 

def md5(str):
    import hashlib
    m=hashlib.md5()
    m.update(str)
    return m.hexdigest()
import urllib
import sys
import json
reload(sys)
sys.setdefaultencoding('utf-8')
source_language="en"
target_language="zh"
f=open("/home/zhangwbnn/code/Text-Detection/textDetection/resource/result.txt",'r')
g=open("/home/zhangwbnn/code/Text-Detection/textDetection/resource/tran.txt",'w')
for line in f.readlines():
    if(line=='\n'):
        continue
    name="http://api.fanyi.baidu.com/api/trans/vip/translate?"
    sign=md5("20170102000035065"+line+"1435660288"+"sap1j_0fjLA0of4qqK9D")
    name+="q="+line+"&from="+source_language+"&to="+target_language+"&appid=20170102000035065"+"&salt=1435660288"+"&sign="+sign
    p=urllib.urlopen(name)
    dic=p.read().decode('utf-8')
    try:  
        js = json.loads(dic)                           #将json格式的结果转换成Python的字典结构  
    except Exception, e:  
        print 'loads Json error.'  
        print e  
        continue  
      
    key = u"trans_result"   
    if key in js:  
        dst = js["trans_result"][0]["dst"]                     #取得翻译后的文本结果  
        outStr = dst                                         #如果翻译出错，则输出原来的文本  

    g.write(outStr.strip().encode('utf-8') + '\n')

    
   #
f.close()
g.close()
    #print dic["trans_result"][0]["dst"]
#q=apple&from=en&to=zh&appid=2015063000000001&salt=1435660288&sign=f89f9594663708c1605f3d736d01d2d4

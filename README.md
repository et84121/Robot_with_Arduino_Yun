#冰棒四足獸[電波追蹤] Robot_with_Arduino_Yun
  
它是一隻以冰棒棍製成的小型四足機器人，一生以電波為食。  
當它的前方擁有大量主人指的頻率之電波時，將會快速的朝向電波前進，並且大口的吃下它們，再露出幸福的眼神。
  
##照片
以後補
  
##構成零件
    動力
      7.4V 1000mAh 鋰聚合物電池  
      八個 - Tower Pro 輝盛 9g servo
      
    控制
      Arduino yun  
      Arduino prototype borad  
      RTL-SDR ( RTL2832U + 820T )  
      
    眼睛
      兩個 - Max7219 with 8*8 LED matrix
      
    鼻子
      超音波 sr - 04
      
    嘴巴
      指向型天線

##TODO List
- [ ] 增加鋰聚合物電池電壓量測功能  
- [ ] 將鋰聚合物電池電力轉供至 yun 上 ( yun 的 vin 只能接入 5v)  
- [ ] 動態步態生成 !!!  
- [ ] rtl-sdr in MIPS CPU
- [ ] 新3D列印機架
- [ ] 手機app

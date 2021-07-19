library(dplyr)

# set working directory
setwd("C:/R file/hustar/Day5")
TSLA<-read.csv(file="TSLA.csv", stringsAsFactors = TRUE)

#(i) Is monthly data or daily data? 
head(TSLA)
#(ii) what is the date with the highest price? 

filter(TSLA,Open==max(TSLA$Open))[1]
filter(TSLA,High==max(TSLA$High))[1]
filter(TSLA,Low==max(TSLA$Low))[1]
filter(TSLA,Adj.Close==max(TSLA$Adj.Close))[1]
filter(TSLA,Close==max(TSLA$Close))[1]

#(iii) Any trend you find out from the given information in kaggle?  

##결측치 확인
sum(is.na(TSLA))
##중복값 확인
sum(duplicated(TSLA))

##박스플롯 확인
par(mfrow=c(1,2))
boxplot(TSLA[,2:5],col=c("orange"))
boxplot(TSLA[,6],col=c("coral"))


library(ggplot2)
install.packages("lubridate")
library(lubridate)

#시계열 시각화를 위한 연도,월,요일
TSLA$Date= as.Date(TSLA$Date)
class(TSLA$Date)
TSLA[,"Year"]=year(TSLA$Date)
TSLA[,"Month"]=month(TSLA$Date)

TSLA[,"Weekday"] = weekdays(TSLA$Date)

head(TSLA)



##연도별 
#전체 가격 시각화
attach(TSLA)
ggplot()+
  geom_line(data=TSLA,aes(y=Open,x= Year,colour="coral",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=High,x= Year,colour="green",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=Low,x= Year,colour="darkblue",group = 1),size=1 )+
  geom_line(data=TSLA,aes(y=Adj.Close,x= Year,colour="purple",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=Close,x= Year,colour="yellow",group = 1),size=1)+
  labs( x="Year", y="price") +
  ggtitle("Year-All")+
  scale_color_discrete(name = "colour", labels = c("Open", "High","Low","Adj.Close","Close"))  

#High Low 시각화
ggplot()+
  geom_line(data=TSLA,aes(y=Low,x= Year,colour="darkblue",group = 1),size=1 )+
  geom_line(data=TSLA,aes(y=High,x= Year,colour="green",group = 1),size=1) +
  labs( x="Year", y="price") +
  ggtitle("Year-HighLow ")+
  scale_color_discrete(name = "colour", labels = c("LOw","High"))  

#Open close 시각화
ggplot()+
  geom_line(data=TSLA,aes(y=Open,x= Year,colour="coral",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=Close,x= Year,colour="yellow",group = 1),size=1)+
  labs( x="Year", y="price") +
  ggtitle("Year-OpenClose ")+
  scale_color_discrete(name = "colour", labels = c("Open","Close"))  

#close Adj.Close시각화-> 거의 동일
ggplot()+
  geom_line(data=TSLA,aes(y=Adj.Close,x= Year,colour="purple",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=Close,x= Year,colour="yellow",group = 1),size=1)+
  labs( x="Year", y="price") +
  scale_color_discrete(name = "colour", labels = c("Adj.Close","Close"))  

##월 시각화
ggplot()+
  geom_line(data=TSLA,aes(y=Open,x= Month,colour="coral",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=High,x= Month,colour="green",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=Low,x= Month,colour="darkblue",group = 1),size=1 )+
  geom_line(data=TSLA,aes(y=Adj.Close,x= Month,colour="purple",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=Close,x= Month,colour="yellow",group = 1),size=1)+
  scale_x_continuous(breaks=c(1, 2, 3, 4, 5, 6,7,8,9,10,11,12)) +
  labs( x="Month", y="price") +
  ggtitle("Month-All")+
  scale_color_discrete(name = "colour", labels = c("Open", "High","Low","Adj.Close","Close"))  

#High Low 시각화
ggplot()+
  geom_line(data=TSLA,aes(y=High,x= Month,colour="green",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=Low,x= Month,colour="darkblue",group = 1),size=1 )+

  scale_x_continuous(breaks=c(1, 2, 3, 4, 5, 6,7,8,9,10,11,12)) +
  labs( x="Month", y="price") +
  ggtitle("Month-HighLow")+
  scale_color_discrete(name = "colour", labels = c("High","Low"))  

#Open close 시각화
ggplot()+
  geom_line(data=TSLA,aes(y=Open,x= Month,colour="coral",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=Close,x= Month,colour="yellow",group = 1),size=1)+
  scale_x_continuous(breaks=c(1, 2, 3, 4, 5, 6,7,8,9,10,11,12)) +
  labs( x="Month", y="price") +
  ggtitle("Month-OpenClose")+
  scale_color_discrete(name = "colour", labels = c("Open", "Close"))  


##요일별 시각화

ggplot()+
  geom_line(data=TSLA,aes(y=Open,x= Weekday,colour="coral",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=High,x= Weekday,colour="green",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=Low,x= Weekday,colour="darkblue",group = 1),size=1 )+
  geom_line(data=TSLA,aes(y=Adj.Close,x= Weekday,colour="purple",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=Close,x= Weekday,colour="yellow",group = 1),size=1)+
  labs( x="Weekday", y="price") +
  ggtitle("Weekday_all")+
  scale_color_discrete(name = "colour", labels = c("Open", "High","Low","Adj.Close","Close"))  



#High Low 시각화

ggplot()+
  geom_line(data=TSLA,aes(y=High,x= Weekday,colour="green",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=Low,x= Weekday,colour="darkblue",group = 1),size=1 )+
  labs( x="Weekday", y="price") +
  ggtitle("Weekday_HighLow")+
  scale_color_discrete(name = "colour", labels = c("High","Low"))  


#Open close 시각화

ggplot()+
  geom_line(data=TSLA,aes(y=Open,x= Weekday,colour="coral",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=Close,x= Weekday,colour="yellow",group = 1),size=1)+
  labs( x="Weekday", y="price") +
  ggtitle("Weekday_OpenClose")+
  scale_color_discrete(name = "colour", labels = c("Open", "Close")) 

##4달간격 전체 시각화

ggplot()+
  geom_line(data=TSLA,aes(y=Open,x= Date,colour="coral",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=High,x= Date,colour="green",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=Low,x= Date,colour="darkblue",group = 1),size=1 )+
  geom_line(data=TSLA,aes(y=Adj.Close,x= Date,colour="purple",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=Close,x= Date,colour="yellow",group = 1),size=1)+
  labs( x="Date", y="price") +
  theme(axis.text.x=element_text(angle=90, hjust=1))+
  scale_x_date(date_breaks = "4 months" , date_labels = "%b-%y")+
  ggtitle("AllData_4Mon_all")+
  scale_color_discrete(name = "colour", labels = c("Open", "High","Low","Adj.Close","Close"))  

#High Low 시각화
ggplot()+
  geom_line(data=TSLA,aes(y=High,x= Date,colour="green",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=Low,x= Date,colour="darkblue",group = 1),size=1 )+
  labs( x="Date", y="price") +
  theme(axis.text.x=element_text(angle=90, hjust=1))+
  ggtitle("AllData_4Mon_HighLow")+
  scale_x_date(date_breaks = "4 months" , date_labels = "%b-%y")+
  scale_color_discrete(name = "colour", labels = c("High","Low")) 



#Open close 시각화
ggplot()+
  geom_line(data=TSLA,aes(y=Open,x= Date,colour="coral",group = 1),size=1) +
  geom_line(data=TSLA,aes(y=Close,x= Date,colour="yellow",group = 1),size=1)+
  labs( x="Date", y="price") +
  theme(axis.text.x=element_text(angle=90, hjust=1))+
  ggtitle("AllData_4Mon_OpenClose")+
  scale_x_date(date_breaks = "4 months" , date_labels = "%b-%y")+
  scale_color_discrete(name = "colour", labels = c("Open","Close")) 


  ##선형회귀식 도출, 상관분석, 트렌드 예측, 계절성, 날별

install.packages("corrplot")
library(corrplot)

head(TSLA)


head(TSLA_1)
TSLA_cor = TSLA_1[,2:7]
TSLA_cor
r<-cor(TSLA_cor) 


pairs(TSLA_cor)
corrplot(r, method="number")


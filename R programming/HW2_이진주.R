
library(dplyr)

# set working directory
setwd("C:/R file/hustar")
SAT_2010<-read.csv(file="SAT_2010.csv", stringsAsFactors = TRUE)

head(SAT_2010)

#A.	“write”와 “math”에 대해 boxplot과 histogram을 그려라. 그린 그래프를 통해 각각의 분포를 설명하고 비교하라.  


attach(SAT_2010)
par(mfrow=c(1,3))
boxplot(math,write, col=c("coral","orange"),names = c("math","wrire"))

hist(math, breaks = 10, col ="coral")
hist(write, breaks = 10, col ="orange")
#B.	산점도를 그려보고 “total” 변수와 가장 의미 있다고 생각하는 변수를 제시하고 설명해라 
pairs(SAT_2010[,1:9])
par(mfrow = c(1,3))

plot(read, total, main = "read")

plot(math , total,main = "math")

plot(write , total,main = "write")

#C.	B에서 선택한 변수와 total 변수 간의 산점도를 그리고 이를 바탕으로 최적적합함수를 추정하여 그래프로 그려라. (선형, 비선형) 
par(mfrow = c(1,3))

plot(read, total, main = "read")
abline(lm(total~read),col = "red",lwd = 2, lty = 1)
lines(lowess(read,total),col="blue",lwd = 3,lty = 2)

plot(math , total,main = "math")
abline(lm(total~math),col = "red",lwd = 2, lty = 1)
lines(lowess(math,total),col="blue",lwd = 3,lty = 2)

plot(write , total,main = "write")
abline(lm(total~write),col = "red",lwd = 2, lty = 1)
lines(lowess(write,total),col="blue",lwd = 3,lty = 2)
detach(SAT_2010)


###search.csv

##A.	주어진 데이터 search.csv, search_gender.csv, search_age.csv, search_local.csv를 불러들여라 (search.csv를 data로 읽었다 하자. data$일 = as.Date(data$일) 을 적용하라.)
data<-read.csv(file="search.csv", stringsAsFactors = TRUE)

head(data)

search_gender<-read.csv(file="search_gender.csv", stringsAsFactors = TRUE)

head(search_gender)

search_age<-read.csv(file="search_age.csv", stringsAsFactors = TRUE)

head(search_age)

search_localr<-read.csv(file="search_local.csv", stringsAsFactors = TRUE)

head(search_localr)
library(ggplot2)
data$일= as.Date(data$일)
class(data$일)
head(data)

#B.	검색량.csv 데이터를 geom_line을 통해 다음과 같이 표현후, 일자별 검색량 변화를 설명하라.
attach(data)


ggplot()+
  geom_line(data=data,aes(y=BTS,x= 일,colour="coral"),size=1) +
  geom_line(data=data,aes(y=zoom,x= 일,colour="green"),size=1) +
  geom_line(data=data,aes(y=라면,x= 일,colour="darkblue"),size=1 )+
  geom_line(data=data,aes(y=코로나,x= 일,colour="purple"),size=1) +
  labs( x="일", y="검색량") +
  scale_color_discrete(name = "colour", labels = c("bts", "zoom","라면","코로나"))

  
  
  
#C.	검색량_성별.csv데이터를 다음과 같이 bar chart로 표현하고, 성별 및 품목별 검색량 차이를 비교하라. 
ggplot(data=search_gender, aes(y=count,x= 품목))+
  geom_bar(stat='identity',aes(fill=성별), colour="black")



ggplot(data=search_gender, aes(y=count,x= 성별,fill=품목))+
  geom_bar(stat='identity',position = "dodge")


#D.	검색량_연령.csv데이터를 다음과 같이 scatter Plot으로 표현해라
head(search_age)

ggplot()+
  geom_point(data=search_age,aes(y=BTS,x= 연령,colour="coral"),size=2) +
  geom_point(data=search_age,aes(y=zoom,x= 연령,colour="green"),size=2) +
  geom_point(data=search_age,aes(y=라면,x= 연령,colour="darkblue"),size=2 )+
  geom_point(data=search_age,aes(y=코로나,x= 연령,colour="purple"),size=2) +
  labs( x="연령", y="라면") +theme_bw()+
  scale_color_discrete(name = "colour", labels = c("bts", "zoom","라면","코로나"))
#E.	검색량_지역.csv데이터를 다음과 같이 Histogram으로 표현해라.(get_histogram(stat=”count”)사용)

head(search_localr)

ggplot(data=search_localr, aes(x=지역))+
  geom_histogram(stat="count",aes(fill=검색어))

#F.	위의 표현된 결과를 통해 각각 BTS, zoom, 라면, 코로나의 지역별 검색량을 비교하라.


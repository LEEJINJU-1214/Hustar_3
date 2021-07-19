
# set working directory
setwd("C:/R file/hustar/Day3")

install.packages("dplyr")
library(dplyr)
##NSC2_M40,NSC2_BNC
NSC2_M40<-read.csv("NSC2_M40_1000.csv")
NSC2_BNC<-read.csv("NSC2_BNC_1000.csv")
head(NSC2_M40)
head(NSC2_BNC)

#1.	다음 Step을 밟은 다음 문제를 해결하시오
#Step 1 : NSC2_M40_1000.csv 에서 2002년부터 2008년까지의 연도별 환자의 방문횟수를 계산한다. 방문횟수를 number라는 변수로 만들어 RN_INDI, STD_YYYY, number를 column으로 가지는 새로운 table을 만들어라.
attach(NSC2_M40)
newData <- filter(NSC2_M40,STD_YYYY>=2002&STD_YYYY<=2008) 

newtable <- newData %>%
  group_by(RN_INDI,STD_YYYY) %>%
  summarise(n())

newtable <-rename(newtable, "number" = "n()")
newtable
#Step 2 : NSC2_BNC_1000.csv와 Step1을 STD_YYYY, RN_INDI를 key로 하여 inner join한다.
innerjointable<-inner_join(newtable,NSC2_BNC, by=c("RN_INDI","STD_YYYY"))
innerjointable

#Step 3: Hint를 이용하여 가장 환자의 방문횟수가 높은 환자의 ID와 해당 연도를 적으시오 
#Hint : arrange(데이터이름 ,desc(기준 변수))

id = arrange(innerjointable ,desc(number))[1,1]

year = arrange(innerjointable ,desc(number))[1,2]
id
year
#2. 다음 데이터에 대해 문제를 해결하시오
SAT<-read.csv("SAT_2010.csv")
head(SAT)
attach(SAT)
#A.	Total 변수의 분산과 평균값은? 중앙값은? 
var(total)
mean(total)
median(total)
#B.	Total 변수가 (평균 – 표준편차, 평균 + 표준편차) 즉, 1시그마 범위 내에 속하는 state의 수는 ?
nrow(filter(SAT,total>=mean(total)-sd(total)&total<=mean(total)+sd(total)) %>% group_by(state))

#C.	Total의 평균으로부터 가장 멀리 떨어진 Total값을 가진 state의 이름은 무엇인가? 
par(mfrow = c(1,1))
boxplot(total, col="orange")
##box plot으로는 가장 멀리 떨어진 값을 찾지 못함
mean(total)-min(total)
max(total)-mean(total)
##min이 가장 멀리 떨어져있음

statename <-filter(SAT,total==min(total))[1]
statename

#D.	ggplot을 이용하여 Salary가 50000이상인 데이터와 이하인 데이터에 대해 Sat_pct와 total 을 이용해 scatter Plot graph를 그리시오. 이 두 그래프를 비교하며 해석하시오. (5점)

library(ggplot2)


scatterhighdata <- filter(SAT, salary>=50000)
scatterlowdata <- filter(SAT, salary<=50000)
ggplot()+
  geom_point(data=scatterhighdata,aes(y=sat_pct,x= total,colour="coral"),size=2)+
  geom_point(data=scatterlowdata,aes(y=sat_pct,x= total,colour="green"),size=2)+
  theme_bw()+ scale_color_discrete(name = "범주", labels = c(">=50000", "<=50000"))


#E.	Total 변수에 대한 정규확률도를 그리고, Shapiro-Wilks test도 하여 비교평가

par(mfrow = c(1,1))
qqnorm(total)
qqline(total, col = 2,cex = 7)

shapiro.test(total)
#정규분포가 아님 , 대립가설 채택



###pizza
pizzar<-read.csv("pizzar.csv")
#3. Garlic bread를 주문/비주문에 따라 피자 배달 평균시간에 차이가 있는가?
head(pizzar)
garlicY <- filter(pizzar,pizzar$Bread==1)
garlicN <- filter(pizzar,pizzar$Bread==0)
#1.1 상자그림(boxplot)을 그리고 비교설명
par(mfrow = c(1,2))
boxplot(garlicY$Delivery, col="orange",main="주문")
boxplot(garlicN$Delivery, col="coral",main="비주문")
##Garlic bread 주문에 따라 배달 평균시간의 차이가 존재
## 주문했을때 더 배달 시간이 빠름

#1.2 ANOVA (혹은 T-Test)를 수행하여 Garlic bread를 주문/비주문에 따라 피자 배달 평균시간에 차이가 유효한지를 설명해라. 그 다음 평균의 차이를 적으시오
attach(pizzar)
a1 <- aov(Bread~Delivery)
summary(a1)
##다르다
mean(garlicN$Delivery)-mean(garlicY$Delivery)

library(dplyr)
setwd("C:/R file/hustar/Day4")
#SAT_1000
SAT = read.csv("SAT_2010.csv")
str(SAT)
# descriptive statistics
summary(SAT)
attach(SAT)
#1.	상기 데이터에 대해 분석을 진행하라.
##A.	해당 데이터에서 중복 데이터가 존재하는가? 존재한다면 해당 변수명을 명시하라. 
duplicated(SAT)
##존재하지 않음

##B.	해당 데이터에서 문자 변수는 총 몇 개가 있는가? 
is.character(state)
is.character(expenditure)
is.character(pupil_teacher_ratio)
is.character(salary)
is.character(read)
is.character(math)
is.character(write)
is.character(total)
is.character(sat_pct)

##1개
##C.	결측치가 있는가? 있다면 몇 개가 있는가? 
##컬럼 기준
is.na(SAT)
###없다

##D.	변수 read와 변수 math와의 상관계수가 0.9보다 큰 변수를 모두 찾아라.  
cor(read,expenditure)
cor(read,pupil_teacher_ratio)
cor(read,salary)
cor(read,write)
cor(read,total)
cor(read,sat_pct)
cor(read,math)

cor(math,expenditure)
cor(math,pupil_teacher_ratio)
cor(math,salary)
cor(math,write)
cor(math,total)
cor(math,sat_pct)
cor(math,read)

##read : write, total, (-sat_pct),math
##math : write, total, (-sat_pct),math



####happy2020
happy = read.csv("happy2020.csv")
head(happy)

###2.	상기 데이터에 대해 분석을 진행하라.
#A.	결측치가 있는가? 결측치가 있는지 확인하여라. 있다면 몇 개가 있는가?
sum(is.na(happy))
##결측치 없음
#B.	행복도(ladder score)에 가장 큰 영향을 미치는 요소 세가지를 상관 분석을 통해서 도출해내라(corrplot 사용 시도 추천). 
#도출후 각각의 산점도와 상관계수를 명시하라.
install.packages("corrplot")
library(corrplot)

head(happy)
happy_cor = happy[,3:10]
happy_cor
r<-cor(happy_cor) 

corrplot(r, method="circle")

pairs(happy_cor)
corrplot(r, method="number")

##Logged.GDP.per.capita, Social.support, Healthy.life.expectancy

#C.	행복지수가 가장 높은 나라와 낮은 나라는 어디이며 각각의 행복지수는 몇인가?
filter(happy, happy$Ladder.score==max(happy$Ladder.score))[1]
max(happy$Ladder.score)
filter(happy, happy$Ladder.score==min(happy$Ladder.score))[1]
min(happy$Ladder.score)
#D.	아래의 그래프를 해석하라. 


#E.	B에서 구한 세가지 요소를 이용하여 종속변수를 행복도로 두고 회귀모형을 수행하고 해석하라

m1<- lm(Ladder.score ~ Logged.GDP.per.capita , data = happy)
summary(m1)
layout(matrix(c(1,2,3,4),2,2)) # optional 4 graphs/page 
plot(m1)
m2<- lm(Ladder.score ~ Social.support , data = happy)
summary(m2)
layout(matrix(c(1,2,3,4),2,2)) # optional 4 graphs/page 
plot(m2)
m3<- lm(Ladder.score ~Healthy.life.expectancy, data = happy)
summary(m3)
layout(matrix(c(1,2,3,4),2,2)) # optional 4 graphs/page 
plot(m3)


### 추가 문제
filePath <- "http://www.sthda.com/sthda/RDoc/example-files/martin-luther-king-i-have-a-dream-speech.txt" 
text <- readLines(filePath)
install.packages("NLP")
library(NLP)
install.packages("tm")
library(tm)
install.packages("wordcloud")
library(wordcloud)
install.packages("RColorBrewer")
library(RColorBrewer)

stopword2 <-c(stopwords('en'),'will','the','and','from','with')
corp1 <-VCorpus(VectorSource(text))
corp1 <-tm_map(corp1, removePunctuation)
corp1 <- tm_map(corp1, removeNumbers)
corp1 <- tm_map(corp1, function(x) removeWords(x,stopword2))
tdm <- TermDocumentMatrix(corp1)
freq <- as.matrix(tdm)
freq1<-sort(rowSums(freq),decreasing = TRUE)

d<-data.frame(word = names(freq1),freq=freq1)

palete <- brewer.pal(7,"Set2")
wordcloud(words = d$word,freq = d$freq,scale = c(5,1),min.freq = 2,random.order = F,colors = palete)


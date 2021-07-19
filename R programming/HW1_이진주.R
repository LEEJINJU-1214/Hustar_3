##실습 1
install.packages("dplyr")
library(dplyr)
setwd("C:/R file/hustar/wk3")

car<-read.csv(file="autompg.csv", stringsAsFactors = TRUE)

#a
a1<-filter(car, cyl==8)
attach(a1)
a1
mean(mean(hp))
detach(a1)
a2<-filter(car, cyl==4)
a2
attach(a2)
mean(mean(hp))
detach(a2)


#b
subdata3 = car %>% subset(grepl("chevrolet",car[,'carname']))
dim(subdata3)


#2
setwd("C:/R file/hustar/Day1_hw1")
baseball = read.csv("Hitters.csv")
head(baseball)


attach(baseball)
#A
baseball['hit_rate']=Hits/AtBat
head(baseball)

#B
baseball['OBP']=(Hits+Walks)/(AtBat+Walks)
head(baseball)
#C
attach(baseball)
Mean_hit <- mean(hit_rate)
Mean_hit
Mean_Obp <- mean(OBP)
Mean_Obp
median(hit_rate)
median(OBP)


#D
h1<-filter(baseball, hit_rate>=Mean_hit)
h2<-filter(baseball, OBP>=Mean_Obp)
head(h1)
dim(h1)
head(h2)
dim(h2)
duplicated (inner_join(h1,h2))
nrow(inner_join(h1,h2))/nrow(baseball)*100

#E
new_baseball = baseball[c('CAtBat', 'CHits', 'CHmRun', 'CRuns', 'CRBI', 'CWalks')]

#F
maxmin = function(x){
  return(  max(x)-min(x))
}

a1 <- new_baseball %>% summarize_all(mean)
a2 <- new_baseball %>% summarize_all(min)
a3 <- new_baseball %>% summarize_all(max)
a4 <- new_baseball %>% summarize_all(maxmin)

table1 <- rbind(a1,a2,a3,a4)
rownames(table1) <- c("mean","min","max","max-min")
table1
table_t <-t(table1)
table_t


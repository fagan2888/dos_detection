library(MASS)

setwd("/home/som/Documents/intrusion_detection")

train <- read.csv("trainLR_set.csv",header = FALSE)
test <- read.csv("testLR_set.csv",header = FALSE)

model <- glm(V35 ~.,family=binomial(link='logit'),data=train)
#s <- summary(model)
#capture.output(s, file = "summary.txt")

fitted.results <- predict(model,newdata=subset(test,select=c(1:34)),type='response')
fitted.results <- ifelse(fitted.results > 0.5,1,0)
misClasificError <- mean(fitted.results != test$V35)
print(paste('Accuracy',1-misClasificError))

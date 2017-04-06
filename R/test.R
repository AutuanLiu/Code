# 体重
X1<-c(35, 40, 40, 42, 37, 45, 43, 37, 44, 42, 41, 39)
mean(X1) # 计算均值
sd(X1) 
# 胸围
X2<-c(60, 74, 64, 71, 72, 68, 78, 66, 70, 65, 73, 75)
mean(X2)
sd(X2) # 计算标准差
plot(X1,X2) # 画散点图
hist(X1) # 画直方图
hist(X2)
# 读取文件
rt<-read.table("exam.txt", head=TRUE); rt
lm.sol<-lm(Weight~Height, data=rt)
summary(lm.sol)

rm (list=ls())
n=5
M=10000
xbar=c(); sdx=c()
pop=rnorm(1000,0,1)
for(i in 1:M){
sam=sample(pop,n,replace=T)
xbar[i]=mean(sam)
sdx[i]=sd(sam)
}
hist(xbar)
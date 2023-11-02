rm(list=ls())
x=1:6
N=c(1,10,100,1000,10000,100000)
px=c()
for(i in 1:length(N)){
sam=sample(x,N[i],replace=T)
nx=length(which(sam==6))
px[i]=nx/N[i]
}
plot(1:length(N),px,type="l",lty=2)
lines(1:length(N),rep(1/6,length(N)),type="l")



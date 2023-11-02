rm(list=ls())
x=1:6
N=c(1,10,100,1000,10000,100000)
px=c()
for(i in 1:length(N)){
sam=sample(x,N[i],replace=T)
nx=length(which(sam==6))
px[i]=nx/N[i]
}
plot(1:length(N),px,type="l",lty=2,ylab="prob. of success",xlab="Tosses",ylim=c(0,0.35),axes=F)
lines(1:length(N),rep(1/6,length(N)),type="l")
axis(1,1:6,N[1:6])
axis(2)



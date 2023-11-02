####---Central Limit Theorem---####
rm(list=ls())
pop=rpois(1000,0.9)
n=c(2,10,30,100)
m=length(n);M=10000
par(mfrow=c(2,2))
xbr=matrix(rep(0,M*m),c(M,m))
for(j in 1:m){
for(i in 1:M){
sam=sample(pop,n[j],replace=T)
xbr[i,j]=mean(sam)
}
hist(xbr[,j],main=paste("Sample Means for n=",n[j]),col=j+1,xlab="sample means")
}





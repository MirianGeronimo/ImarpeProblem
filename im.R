setwd("/home/mirian/Descargas/claseMrak/elementos finitos")
resul <- read.table(file = "Myfile.txt", header=TRUE)
print(resul)

with(resul,plot(tiempos,Poblacion))




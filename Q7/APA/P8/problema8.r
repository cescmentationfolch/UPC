#valors x_i
x <- runif(n = 100, min = 0, max = 100)
print("X:")
print(x)

#valors p_i normalitzats
p <- runif(n = 100, min = 0, max = 1)
p = p/sum(p)
print("P:")
print(p)

#funcio f
f <- function(s) {
    result <- 0
    for (i in 1:100)
        result = result + p[i]*(s-x[i])^2
    return(result)
}
    
#plot de la funcio f(x)
curve(f,0,100)    
    
#calcula el valor t per el que f(x) es minim
t <- weighted.mean(x,p)
print("Minim:")
print(t)

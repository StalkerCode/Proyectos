module Utils
export factorial, mcd, mcm
function factorial(n)
    if n < 0
        return "Error: Factorial of a negative number is undefined"
    end

    result = 1
    for i in 1:n
        result *= i
    end
    return result
end

# funcion de maximo comun divisor
function mcd(a, b)
    if a < 0 || b < 0
        return "Error: mcd of a negative number is undefined"
    end
    while b != 0
        a, b = b, a % b
    end
    return a
end

# funcion de minimo comun multiplo
function mcm(a, b)
    if a < 0 || b < 0
        return "Error: mcm of a negative number is undefined"
    end
    return (a * b) ÷ mcd(a, b)
end
#=
println(factorial(5))

println(mcd(2,7))

println(mcm(12,26))
=#
end
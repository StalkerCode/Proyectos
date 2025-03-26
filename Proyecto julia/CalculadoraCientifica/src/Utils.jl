#Utils.jl
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

println(factorial(5))
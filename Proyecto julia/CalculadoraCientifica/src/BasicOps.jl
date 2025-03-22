module BasicOps

export add, subtract, multiply, divide, modulus

function add(num1, num2)
    return num1 + num2
end

function subtract(num1, num2)
    return num1 - num2
end


function multiply(num1, num2)
    return num1 * num2
end

function divide(num1, num2)
    if num2 == 0
        return "Error: Division by zero"
    else
        return num1 / num2
    end
end


function modulus(num1, num2)
    if num2 == 0
        return "Error: Division by zero"
    else
        return num1 % num2
    end
end

#=
# testing the functions

println(add(5, 3))  # Output: 8

println(subtract(5, 3))  # Output: 2

println(multiply(5, 3))  # Output: 15

println(divide(5, 3))  # Output: 1.6666666666666667

println(divide(5, 0))  # Output: Error: Division by zero

println(modulus(5, 3))  # Output: 2
=#
end
module explore_data
export show_head, show_tail, agrupar_datos_flores

function show_head(dato, n=5)
    println("Primeras $n filas de los datos:")
    for i in 1:n
        println(dato[i])
    end

end

function show_tail(dato, n=5)
    println("Últimas $n filas de los datos:")
    for i in (length(dato)-n+1):length(dato)
        println(dato[i])
    end
end

# Funcion para agrupar los datos en un diccionario por especie de flor
function agrupar_datos_flores(datos)
    datos_agrupados = Dict{String,Dict{String,Vector{Float64}}}()
    for fila in datos
        especie = fila[end]
        if !haskey(datos_agrupados, especie)
            datos_agrupados[especie] = Dict(
                "longitud_sepalo" => Float64[],
                "ancho_sepalo" => Float64[],
                "longitud_petalo" => Float64[],
                "ancho_petalo" => Float64[]
            )
        end

        push!(datos_agrupados[especie]["longitud_sepalo"], fila[1])
        push!(datos_agrupados[especie]["ancho_sepalo"], fila[2])
        push!(datos_agrupados[especie]["longitud_petalo"], fila[3])
        push!(datos_agrupados[especie]["ancho_petalo"], fila[4])
    end

    return datos_agrupados
end

end
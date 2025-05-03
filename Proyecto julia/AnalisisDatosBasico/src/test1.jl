using CSV
#using DataFrames

# Cargar los datos de las flores desde el archivo CSV
function cargar_hoja()
    path = "src/data/iris_data.csv"
    datos = []
    open(path, "r") do archivo
        for linea in eachline(archivo)
            # Omitir líneas vacías o que solo tienen espacios
            if isempty(strip(linea))
                continue
            end
            subfila = split(linea, ",")
            nueva_fila = Any[parse(Float64, dato) for dato in subfila[1:end-1]]
            push!(nueva_fila, subfila[end])
            push!(datos, nueva_fila)
        end
    end
    return datos
end

# Funcion para agrupar los datos en un diccionario por especie de flor
function agrupar_datos(datos)
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

# funcion para calcular la media de un vector de numeros
function media(datos)
    return sum(datos) / length(datos)
end

function desviacion_estandar(datos)
    n = length(datos)
    media_datos = media(datos)
    varianza = sum((x - media_datos)^2 for x in datos) / (n)
    return sqrt(varianza)

end

struct Flor
    especie::String

    media_longitud_sepalo::Float64
    media_ancho_sepalo::Float64
    media_longitud_petalo::Float64
    media_ancho_petalo::Float64

    desviacion_longitud_sepalo::Float64
    desviacion_ancho_sepalo::Float64
    desviacion_longitud_petalo::Float64
    desviacion_ancho_petalo::Float64
end


function calcular_estadisticas(datos_agrupados::Dict{String,Dict{String,Vector{Float64}}})
    estadisticas = Dict{String,Flor}()
    for (especie, datos) in datos_agrupados
        media_longitud_sepalo = media(datos["longitud_sepalo"])
        media_ancho_sepalo = media(datos["ancho_sepalo"])
        media_longitud_petalo = media(datos["longitud_petalo"])
        media_ancho_petalo = media(datos["ancho_petalo"])
        desviacion_longitud_sepalo = desviacion_estandar(datos["longitud_sepalo"])
        desviacion_ancho_sepalo = desviacion_estandar(datos["ancho_sepalo"])
        desviacion_longitud_petalo = desviacion_estandar(datos["longitud_petalo"])
        desviacion_ancho_petalo = desviacion_estandar(datos["ancho_petalo"])
        estadisticas[especie] = Flor(especie, media_longitud_sepalo, media_ancho_sepalo, media_longitud_petalo, media_ancho_petalo, desviacion_longitud_sepalo, desviacion_ancho_sepalo, desviacion_longitud_petalo, desviacion_ancho_petalo)
    end
    return estadisticas
end

#! acomodarlo para tener un maximo de 4 decimales
function imprimir_estadisticas(estadisticas::Dict{String,Flor})
    for (especie, flor) in estadisticas
        println("Especie: ", flor.especie)
        println("Media longitud sépalo: ", flor.media_longitud_sepalo)
        println("Media ancho sépalo: ", flor.media_ancho_sepalo)
        println("Media longitud pétalo: ", flor.media_longitud_petalo)
        println("Media ancho pétalo: ", flor.media_ancho_petalo)
        println("Desviación estándar longitud sépalo: ", flor.desviacion_longitud_sepalo)
        println("Desviación estándar ancho sépalo: ", flor.desviacion_ancho_sepalo)
        println("Desviación estándar longitud pétalo: ", flor.desviacion_longitud_petalo)
        println("Desviación estándar ancho pétalo: ", flor.desviacion_ancho_petalo)
        println("-----------------------------")
    end
end

datos_flores=agrupar_datos(cargar_hoja())
estadisticas_flores = calcular_estadisticas(datos_flores)
imprimir_estadisticas(estadisticas_flores)
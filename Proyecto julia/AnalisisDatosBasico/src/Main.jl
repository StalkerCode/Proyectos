include("load_data.jl")
include("explore_data.jl")
include("analyze_data.jl")

using .load_data: cargar_hoja
using .explore_data: show_head, show_tail, agrupar_datos_flores
using .analyze_data: media, varianza, desviacion_estandar

# Definir una estructura para almacenar las estadísticas de cada especie de flor
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

# Función para calcular las estadísticas de cada especie de flor
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

function imprimir_estadisticas(estadisticas::Dict{String,Flor})
    for (especie, flor) in estadisticas
        println("Especie: ", flor.especie)
        println("Media longitud sépalo: ", round(flor.media_longitud_sepalo, digits=4))
        println("Media ancho sépalo: ", round(flor.media_ancho_sepalo, digits=4))
        println("Media longitud pétalo: ", round(flor.media_longitud_petalo, digits=4))
        println("Media ancho pétalo: ", round(flor.media_ancho_petalo, digits=4))
        println("Desviación estándar longitud sépalo: ", round(flor.desviacion_longitud_sepalo, digits=4))
        println("Desviación estándar ancho sépalo: ", round(flor.desviacion_ancho_sepalo, digits=4))
        println("Desviación estándar longitud pétalo: ", round(flor.desviacion_longitud_petalo, digits=4))
        println("Desviación estándar ancho pétalo: ", round(flor.desviacion_ancho_petalo, digits=4))
        println("-----------------------------")
    end
end

println("Estadísticas de las flores:")
println("\n-----------------------------\n")
datos = cargar_hoja()
datos_Agrupados = agrupar_datos_flores(datos)
estadisticas = calcular_estadisticas(datos_Agrupados)
imprimir_estadisticas(estadisticas)

println("------------------------------")
println("\nFin del programa.")
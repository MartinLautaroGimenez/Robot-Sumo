# Proyecto de Arduino con Puente L298N, Sensor de Ultrasonido y TCR5000

Este repositorio contiene el código y la documentación para un proyecto que utiliza Arduino junto con un puente L298N, un sensor de ultrasonido y un módulo TCR5000.

## Descripción del Proyecto

Este proyecto está diseñado para controlar un motor DC utilizando un Arduino y un puente H L298N. El sensor de ultrasonido se utiliza para detectar objetos y evitar colisiones, mientras que el módulo TCR5000 se emplea para la detección de línea en aplicaciones de seguidor de línea.

## Componentes Necesarios

- Arduino (cualquier modelo compatible)
- Puente H L298N
- Sensor de Ultrasonido
- Módulo TCR5000 (para detección de línea)
- Motor DC
- Batería o fuente de alimentación
- Cables y conectores

## Conexiones

Asegúrate de realizar las conexiones adecuadas entre los componentes. Puedes encontrar un esquema de conexión en el archivo `conexiones.png` en este repositorio.

## Código Fuente

El código fuente para este proyecto se encuentra en el archivo `codigo.ino`. Abre este archivo en el entorno de desarrollo Arduino y carga el código en tu placa Arduino.

## Uso

Una vez cargado el código en tu Arduino y conectados los componentes según el esquema de conexiones, podrás ejecutar el proyecto. El Arduino controlará el motor DC, utilizará el sensor de ultrasonido para evitar obstáculos y el módulo TCR5000 para seguir una línea si está configurado para ello.

---

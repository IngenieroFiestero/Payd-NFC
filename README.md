# Payd-NFC
El sistema consta de una aplicación para smartphone y un dispositivo controlado por arduino que sirve para dispensar monedas. 
###Android
La aplicacion utiliza una sencilla interfaz en la que marcas el saldo en monedas que deseas adquirir asi como un boton para pedirlas a traves de NFC.

### Arduino
Este consta de un lector NFC, un sevo y un par de leds. Utiliza el servo para expulsar las monedas desde un tubo.

### Posibilidades del proyecto
Se pueden conectar todos los expendedores de un area a un nodo central conectado a internet para su manutencion y revision en tiempo real. De otra manera podrias utilizar la conexion al movil como modem para transmitir los datos a internet, de tal manera que tambien estaria siempre actualizado. Todo depende del modelo de implantacion, en solitario y en grupo

Un ejemplo de la implantacion en solitario seria colocar uno en las paradas o estaciones de bus. Muchos de estos servicios no aceptan pagos con billetes mayores de 5€, por lo cual seria aconsejable disponer de efectivo en monedas. Tambien en areas de tiendas, donde simplemente puedes querer un refresco y te veas forzado a pagar con billete.

El ejemplo de implantacion en grupo y control por nodo seria una facultad universitaria. En ella hay multitud de maquinas de vending donde cada vez mas son aceptados los billetes pero no siempre es la opcion mas conveniente, pues pagar 20€ y recibir 19€ en monedas como cambio no suele ser del agrado de nadie. Esto obliga a ir a la cafeteria, aguantar colas y precios posiblemente mas altos o simplemente no disponer del producto que tu quieres, ya que suelen tener gran variedad.

El funcionamiento del nodo seria la de control de todas las maquinas y estadisticas de uso. Asi, en un proyecto piloto podria analizarse donde el impacto es mas fuerte. Dotaria a las maquinas de conexion a internet permanente y diagnostico a distancia.

La conexion de las maquinas a internet se haria identificando cada dispensador con un token seguro y comprobando concordancia de claves. El sistema de pago podria ser la pasarela propia de NFC de La Caixa.

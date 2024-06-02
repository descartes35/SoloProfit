<?php ob_start() ?>
<h1 class="text-center">Resumen General</h1>
<hr>
<div class="container mt-5">
    <!-- <h1 class="text-center">Resumen General</h1> -->
    <!-- <hr> -->
    <div class="row">
        <div class="col-md-6">
            <h2 class="h2Resumen"><u>Citas</u></h2>
            <?php foreach ($citas as $cita) : ?>
                <p><span class="cabecera-subtle-glow">Fecha y Hora:</span> <?php echo $cita['FechaHora']; ?></p>
                <p><span class="cabecera-subtle-glow">Descripción:</span> <?php echo $cita['Descripcion']; ?></p>
                <hr>
            <?php endforeach; ?>
        </div>
        <div class="col-md-6">
            <h2 class="h2Resumen"><u>Proveedores</u></h2>
            <?php foreach ($proveedores as $proveedor) : ?>
                <p><span class="cabecera-subtle-glow">Nombre</span>: <?php echo $proveedor['Nombre']; ?></p>
                <p><span class="cabecera-subtle-glow">Email:</span> <?php echo $proveedor['Email']; ?></p>
                <p><span class="cabecera-subtle-glow">Teléfono:</span> <?php echo $proveedor['Telefono']; ?></p>
                <p><span class="cabecera-subtle-glow">Dirección:</span> <?php echo $proveedor['Direccion']; ?></p>
                <p><span class="cabecera-subtle-glow">Descripción:</span> <?php echo $proveedor['Descripcion']; ?></p>
                <hr>
            <?php endforeach; ?>
        </div>
    </div>
    <div class="row mt-5">
        <div class="col-md-6">
            <h2 class="h2Resumen"><u>Información Financiera</u></h2>
            <h3 class="h3Resumen">Ingresos</h3>
            <?php foreach ($ingresos as $ingreso) : ?>
                <p><span class="cabecera-subtle-glow">Usuario:</span> <?php echo $ingreso['Nombre'] . ' ' . $ingreso['Apellidos']; ?></p>
                <p><span class="cabecera-subtle-glow">Total Ingresos:</span> <?php echo $ingreso['TotalIngresos']; ?>€</p>
                <hr>
            <?php endforeach; ?>
            <h3 class="h3Resumen">Gastos</h3>
            <?php foreach ($gastos as $gasto) : ?>
                <p><span class="cabecera-subtle-glow">Usuario:</span> <?php echo $gasto['Nombre'] . ' ' . $gasto['Apellidos']; ?></p>
                <p><span class="cabecera-subtle-glow">Total Gastos:</span> <?php echo $gasto['TotalGastos']; ?>€</p>
                <hr>
            <?php endforeach; ?>
            <h3 class="h3Resumen">Balance Financiero</h3>
            <?php foreach ($balances as $balance) : ?>
                <p><span class="cabecera-subtle-glow">Usuario:</span> <?php echo $balance['Nombre'] . ' ' . $balance['Apellidos']; ?></p>
                <p><span class="cabecera-subtle-glow">Total Ingresos:</span> <?php echo $balance['TotalIngresos']; ?>€</p>
                <p><span class="cabecera-subtle-glow">Total Gastos:</span> <?php echo $balance['TotalGastos']; ?>€</p>
                <p><span class="cabecera-subtle-glow">Balance:</span> <?php echo $balance['Balance']; ?>€</p>
                <hr>
            <?php endforeach; ?>
        </div>
        <div class="col-md-6">
            <h2 class="h2Resumen"><u>Inventario</u></h2>
            <h3 class="h3Resumen">Artículos</h3>
            <?php foreach ($articulos as $articulo) : ?>
                <p><span class="cabecera-subtle-glow">Nombre:</span> <?php echo $articulo['Nombre']; ?></p>
                <p><span class="cabecera-subtle-glow">Descripción:</span> <?php echo $articulo['Descripcion']; ?></p>
                <p><span class="cabecera-subtle-glow">Tipo:</span> <?php echo $articulo['Tipo']; ?></p>
                <hr>
            <?php endforeach; ?>
        </div>
    </div>
</div>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/base.php'; ?>
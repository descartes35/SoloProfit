<?php ob_start() ?>
<h3>Inventario->Productos</h3>
<hr>
<div class="container text-center">
    <img src="" alt="" srcset=""><!--Aquí una imagen que identifique un poco más la página (archivo) en sí. Por ver.-->
    <h4>Aquí puedes gestionar todo lo que tenga que ver con los <u>productos</u> que ofreces a tus clientes</h4>
    <br>
    <button type="button" class="btn btn-outline-success"><a class="colorBlanco" href="index.php?ctl=ProductoAñadir">Añadir un producto</a></button>
    <button type="button" class="btn btn-outline-success"><a class="colorBlanco" href="index.php?ctl=ProductoGestion">Ver/gestionar productos</a></button>
</div>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../../base.php'; ?>
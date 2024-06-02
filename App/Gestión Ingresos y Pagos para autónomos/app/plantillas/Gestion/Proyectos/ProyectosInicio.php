<?php ob_start() ?>
<h3>Gestión->Proyectos</h3>
<hr>
<div class="container text-center">
    <img src="" alt="" srcset=""><!--Aquí una imagen que identifique un poco más la página (archivo) en sí. Por ver.-->
    <h4>Aquí puedes gestionar todo lo que tenga que ver con tus <u>proyectos</u></h4>
    <br>
    <button type="button" class="btn btn-outline-success"><a class="colorBlanco" href="index.php?ctl=ProyectosAñadir">Añadir un proyecto</a></button>
    <button type="button" class="btn btn-outline-success"><a class="colorBlanco" href="index.php?ctl=ProyectosGestion">Ver/gestionar proyectos</a></button>
</div>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../../base.php'; ?>
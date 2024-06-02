<?php ob_start() ?>
<h3>Generar reporte financiero</h3>
<hr>
<p>Aquí puedes generar un archivo pdf con tus datos detallados.</p>
<div class="text-center">
    <a href="index.php?ctl=generarReporte">
        <button class="btn btn-success">Haz clic aquí para generar el reporte</button>
    </a>
</div>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../../base.php'; ?>
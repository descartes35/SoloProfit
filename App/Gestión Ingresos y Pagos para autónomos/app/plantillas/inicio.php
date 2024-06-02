<?php ob_start() ?>

<?php
if (isset($_SESSION['Nombre']) && isset($_SESSION['Apellidos'])) {
    $nombre = $_SESSION['Nombre'] . ', ' . $_SESSION['Apellidos'];
?>
    <hr>
    <h2>Hola <?php echo ($nombre) ?></h2>
<?php
}
?>
<hr>
<br>
<!-- <div class="container"> -->
<div id="carouselExampleSlidesOnly" class="carousel carousel-dark slide" data-bs-ride="carousel">
    <div class="carousel-inner">
        <div class="carousel-item active">
            <img src="web/imagenes/imagenInicio4.jpg" class="d-block w-100" alt="Autónomo botánico">
            <div class="carousel-caption d-none d-md-block text-dark-emphasis bg-success-subtle">
                <h5>Domina tus números y toma el control total de tu éxito financiero con nuestra herramienta intuitiva.</h5>
                <p>Simplifica la gestión de tu negocio y concéntrate en lo que realmente importa: hacer crecer tu emprendimiento.</p>
            </div>
        </div>
        <div class="carousel-item">
            <img src="web/imagenes/imagenInicio2.jpg" class="d-block w-100" alt="Autónomo mirando su móvil mienntras sujeta unas hojas">
            <div class="carousel-caption d-none d-md-block text-dark-emphasis bg-success-subtle">
                <h5>Gestiona tus ingresos y gastos de forma sencilla y eficiente para impulsar tu negocio.</h5>
                <p>Haz crecer tu negocio con una gestión financiera inteligente y eficiente.</p>
            </div>
        </div>
        <div class="carousel-item">
            <img src="web/imagenes/imagenInicio3.jpg" class="d-block w-100" alt="Autónomo carpintero">
            <div class="carousel-caption d-none d-md-block text-dark-emphasis bg-success-subtle">
                <h5>Optimiza tu flujo de efectivo y mantén tus finanzas bajo control con nuestra aplicación.</h5>
                <p>Optimiza tus recursos y toma decisiones informadas para alcanzar tus metas financieras.</p>
            </div>
        </div>
        <div class="carousel-item">
            <img src="web/imagenes/imagenInicio1.jpg" class="d-block w-100" alt="Autónomo con su portátil">
            <div class="carousel-caption d-none d-md-block text-dark-emphasis bg-success-subtle">
                <h5>Controla tus finanzas como nunca antes y alcanza tus objetivos con confianza.</h5>
                <p>Organiza tus finanzas con facilidad y controla tus ingresos y gastos como un profesional.</p>
            </div>
        </div>
    </div>
</div>
<!-- </div> -->

<?php $contenido = ob_get_clean() ?>

<?php include_once __DIR__ . '/base.php' ?>
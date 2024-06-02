<?php ob_start() ?>
<h3>Gestión-><a class="enlaceVerde" href="index.php?ctl=ProyectosInicio">Proyectos</a>->Añadir</h3>
<hr>
<form class="row g-3" method="post">
    <div class="col-md-6">
        <label for="Nombre" class="form-label">Nombre del Proyecto:</label>
        <input type="text" class="form-control" id="Nombre" name="Nombre" required>
    </div>
    <div class="col-12">
        <label for="Descripcion" class="form-label">Descripción:</label>
        <textarea class="form-control" id="Descripcion" name="Descripcion" rows="3" required></textarea>
    </div>
    <div class="col-md-6">
        <label for="FechaInicio" class="form-label">Fecha de Inicio:</label>
        <input type="date" class="form-control" id="FechaInicio" name="FechaInicio" required>
    </div>
    <div class="col-md-6">
        <label for="FechaFin" class="form-label">Fecha de Fin:</label>
        <input type="date" class="form-control" id="FechaFin" name="FechaFin" required>
    </div>
    <div class="col-12 text-center">
        <br>
        <button type="submit" class="btn btn-warning">Crear Proyecto</button>
    </div>
    <div class="error">
        <?php
        if (isset($_SESSION['errorProyecto'])) {
            echo "<p>" . htmlspecialchars($_SESSION['errorProyecto']) . "</p>";
        }
        ?>
    </div>
</form>

<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../../base.php'; ?>
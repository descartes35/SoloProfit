<?php ob_start() ?>
<h3>Gestión-><a class="enlaceVerde" href="index.php?ctl=ProyectosInicio">Proyectos</a>->Editar</h3>
<hr>
<form method="post" action="index.php?ctl=ProyectosEditar&id=<?php echo htmlspecialchars($proyecto['IDProyecto']); ?>">
    <div class="mb-3">
        <label for="nombre" class="form-label">Nombre</label>
        <input type="text" class="form-control" id="nombre" name="nombre" value="<?php echo htmlspecialchars($proyecto['Nombre']); ?>" required>
    </div>
    <div class="mb-3">
        <label for="descripcion" class="form-label">Descripción</label>
        <textarea class="form-control" id="descripcion" name="descripcion" rows="3" required><?php echo htmlspecialchars($proyecto['Descripcion']); ?></textarea>
    </div>
    <div class="mb-3">
        <label for="fechaInicio" class="form-label">Fecha de Inicio</label>
        <input type="date" class="form-control" id="fechaInicio" name="fechaInicio" value="<?php echo htmlspecialchars($proyecto['FechaInicio']); ?>" required>
    </div>
    <div class="mb-3">
        <label for="fechaFin" class="form-label">Fecha de Fin</label>
        <input type="date" class="form-control" id="fechaFin" name="fechaFin" value="<?php echo htmlspecialchars($proyecto['FechaFin']); ?>" required>
    </div>
    <button type="submit" class="btn btn-primary">Actualizar</button>
</form>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../../base.php'; ?>

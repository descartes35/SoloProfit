<?php ob_start() ?>
<h3>Inventario-><a class="enlaceVerde" href="index.php?ctl=ServiciosInicio">Servicios</a>->Editar</h3>
<hr>
<form method="post" action="index.php?ctl=ServiciosEditar&id=<?php echo htmlspecialchars($servicio['IDArticulo']); ?>">
    <div class="mb-3">
        <label for="nombre" class="form-label">Nombre</label>
        <input type="text" class="form-control" id="nombre" name="nombre" value="<?php echo htmlspecialchars($servicio['Nombre']); ?>" required>
    </div>
    <div class="mb-3">
        <label for="categoria" class="form-label">Categoría</label>
        <input type="text" class="form-control" id="categoria" name="categoria" value="<?php echo htmlspecialchars($servicio['Categoria']); ?>" required>
    </div>
    <div class="mb-3">
        <label for="descripcion" class="form-label">Descripción</label>
        <textarea class="form-control" id="descripcion" name="descripcion" rows="3" required><?php echo htmlspecialchars($servicio['Descripcion']); ?></textarea>
    </div>
    <div class="mb-3">
        <label for="fechaRegistro" class="form-label">Fecha de Registro</label>
        <input type="date" class="form-control" id="fechaRegistro" name="fechaRegistro" value="<?php echo htmlspecialchars($servicio['FechaRegistro']); ?>" required>
    </div>
    <div class="mb-3">
        <label for="tipo" class="form-label">Tipo</label>
        <input type="text" class="form-control" id="tipo" name="tipo" value="<?php echo htmlspecialchars($servicio['Tipo']); ?>" required>
    </div>
    <button type="submit" class="btn btn-primary">Actualizar</button>
</form>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../../base.php'; ?>
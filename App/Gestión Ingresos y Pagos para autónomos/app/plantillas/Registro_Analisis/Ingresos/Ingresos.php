<?php ob_start() ?>
<h3>Registrar ingreso</h3>
<hr>
<form method="post" action="index.php?ctl=registroIngreso">

    <div class="mb-3">
        <label for="categoriaIngreso" class="form-label">Categoría Ingreso</label>
        <input type="text" class="form-control" id=categoriaIngreso" name="categoriaIngreso" required>
    </div>
    <div class="mb-3">
        <label for="monto_ingreso" class="form-label">Monto</label>
        <input type="number" class="form-control" id="monto_ingreso" name="monto_ingreso" min="0" step="0.01" required>
    </div>
    <div class="mb-3">
        <label for="fecha_ingreso" class="form-label">Fecha</label>
        <input type="date" class="form-control" id="fecha_ingreso" name="fecha_ingreso" required>
    </div>
    <div class="mb-3">
        <label for="descripcion_ingreso" class="form-label">Descripción</label>
        <textarea class="form-control" id="descripcion_ingreso" name="descripcion_ingreso" rows="3"></textarea>
    </div>
    <button type="submit" class="btn btn-warning">Guardar Ingreso</button>
</form>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../../base.php'; ?>
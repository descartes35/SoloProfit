<?php ob_start() ?>
<h3>Registrar gasto</h3>
<hr>
<form method="post" action="index.php?ctl=registroGasto">
    <div class="mb-3">
        <label for="categoriaGasto" class="form-label">Categoría Gasto</label>
        <input type="text" class="form-control" id=categoriaGasto" name="categoriaGasto" required>
    </div>
    <div class="mb-3">
        <label for="monto_gasto" class="form-label">Monto</label>
        <input type="number" class="form-control" id="monto_gasto" name="monto_gasto" min="0" step="0.01" required>
    </div>
    <div class="mb-3">
        <label for="fecha_gasto" class="form-label">Fecha</label>
        <input type="date" class="form-control" id="fecha_gasto" name="fecha_gasto" required>
    </div>
    <div class="mb-3">
        <label for="descripcion_gasto" class="form-label">Descripción</label>
        <textarea class="form-control" id="descripcion_gasto" name="descripcion_gasto" rows="3"></textarea>
    </div>
    <button type="submit" class="btn btn-warning">Guardar Gasto</button>
</form>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../../base.php'; ?>
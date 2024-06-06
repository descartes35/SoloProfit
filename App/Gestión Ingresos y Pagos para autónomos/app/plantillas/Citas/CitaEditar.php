<?php ob_start() ?>
<h3 class="text-center">Editar Cita</h3>
<hr>
<form action="index.php?ctl=CitasEditar" method="POST">
    <input type="hidden" name="IDCita" value="<?php echo htmlspecialchars($cita['IDCita']); ?>">
    <div class="form-group">
        <label for="FechaHora">Fecha y Hora:</label>
        <input type="datetime-local" class="form-control" id="FechaHora" name="FechaHora" value="<?php echo date('Y-m-d\TH:i', strtotime($cita['FechaHora'])); ?>" required>
    </div>
    <div class="form-group">
        <label for="Descripcion">Descripción:</label>
        <textarea class="form-control" id="Descripcion" name="Descripcion" rows="3" required><?php echo htmlspecialchars($cita['Descripcion']); ?></textarea>
    </div>
    <br>
    <button type="submit" class="btn btn-warning">Guardar cambios</button>
    <a href="index.php?ctl=VerCitas" class="btn btn-secondary">Cancelar</a>
</form>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../base.php'; ?>

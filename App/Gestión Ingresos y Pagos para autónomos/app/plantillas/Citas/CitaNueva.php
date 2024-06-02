<?php ob_start() ?>
<h3 class="text-center">Aquí puedes añadir tus citas</h3>
<hr>
<form class="row g-3" method="post">
    <div class="col-md-6">
        <label for="FechaHora" class="form-label">Fecha y Hora:</label>
        <?php
        $fechaHoraActual = date('Y-m-d\TH:i', strtotime('now'));
        ?>
        <input type="datetime-local" class="form-control" id="FechaHora" name="FechaHora" min="<?= $fechaHoraActual ?>" required>
    </div>
    <div class="col-12">
        <label for="Descripcion" class="form-label">Descripción:</label>
        <textarea class="form-control" id="Descripcion" name="Descripcion" rows="3" required></textarea>
    </div>
    <div class="col-12">
        <br>
        <button type="submit" class="btn btn-warning">Crear cita</button>
    </div>
</form>

<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../base.php'; ?>

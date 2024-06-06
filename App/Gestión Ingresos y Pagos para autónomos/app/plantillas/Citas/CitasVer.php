<?php ob_start() ?>
<h3 class="text-center">Resumen de Citas</h3>
<hr>
<?php if (!empty($citas)) : ?>
    <ul class="list-group">
        <?php foreach ($citas as $cita) : ?>
            <li class="list-group-item d-flex justify-content-between align-items-center">
                <div>
                    <strong>Fecha y Hora:</strong> <?php echo htmlspecialchars($cita['FechaHora']); ?><br>
                    <strong>Descripción:</strong> <?php echo htmlspecialchars($cita['Descripcion']); ?><br>
                </div>
                <div>
                    <a href="index.php?ctl=CitasEditar&id=<?php echo $cita['IDCita']; ?>" class="btn btn-primary btn-sm">Editar</a>
                    <a href="index.php?ctl=CitasBorrar&id=<?php echo $cita['IDCita']; ?>" class="btn btn-danger btn-sm">Borrar</a>
                </div>
            </li>
        <?php endforeach; ?>
    </ul>
<?php else : ?>
    <p>No se encontraron citas.</p>
<?php endif; ?>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../base.php'; ?>
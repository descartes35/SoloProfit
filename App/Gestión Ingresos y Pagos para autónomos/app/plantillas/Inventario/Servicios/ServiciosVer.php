<?php ob_start() ?>
<h3>Inventario-><a class="enlaceVerde" href="index.php?ctl=ServiciosInicio">Servicios</a>->Ver</h3>
<hr>
<?php if (!empty($servicios)) : ?>
    <ul class="list-group">
        <?php foreach ($servicios as $servicio) : ?>
            <li class="list-group-item d-flex justify-content-between align-items-center">
                <div>
                    <strong>Nombre:</strong> <?php echo htmlspecialchars($servicio['Nombre']); ?><br>
                    <strong>Categoría:</strong> <?php echo htmlspecialchars($servicio['Categoria']); ?><br>
                    <strong>Descripción:</strong> <?php echo htmlspecialchars($servicio['Descripcion']); ?><br>
                    <strong>Fecha de Registro:</strong> <?php echo htmlspecialchars($servicio['FechaRegistro']); ?><br>
                    <strong>Tipo:</strong> <?php echo htmlspecialchars($servicio['Tipo']); ?><br>
                </div>
                <div>
                    <a href="index.php?ctl=ServiciosEditar&id=<?php echo $servicio['IDArticulo']; ?>" class="btn btn-primary btn-sm">Editar</a>
                    <a href="index.php?ctl=ServiciosBorrar&id=<?php echo $servicio['IDArticulo']; ?>" class="btn btn-danger btn-sm">Borrar</a>
                </div>
            </li>
        <?php endforeach; ?>
    </ul>
<?php else : ?>
    <p>No se encontraron servicios.</p>
<?php endif; ?>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../../base.php'; ?>

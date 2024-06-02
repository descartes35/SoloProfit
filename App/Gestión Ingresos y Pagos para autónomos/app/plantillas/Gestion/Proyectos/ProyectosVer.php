<?php ob_start() ?>
<h3>Gestión-><a class="enlaceVerde" href="index.php?ctl=ProyectosInicio">Proyectos</a>->Ver</h3>
<hr>
<?php if (!empty($proyectos)) : ?>
    <ul class="list-group">
        <?php foreach ($proyectos as $proyecto) : ?>
            <li class="list-group-item d-flex justify-content-between align-items-center">
                <div>
                    <strong>Nombre:</strong> <?php echo htmlspecialchars($proyecto['Nombre']); ?><br>
                    <strong>Descripción:</strong> <?php echo htmlspecialchars($proyecto['Descripcion']); ?><br>
                    <strong>Fecha de Inicio:</strong> <?php echo htmlspecialchars($proyecto['FechaInicio']); ?><br>
                    <strong>Fecha de Fin:</strong> <?php echo htmlspecialchars($proyecto['FechaFin']); ?><br>
                </div>
                <div>
                    <a href="index.php?ctl=ProyectosEditar&id=<?php echo $proyecto['IDProyecto']; ?>" class="btn btn-primary btn-sm">Editar</a>
                    <a href="index.php?ctl=ProyectosBorrar&id=<?php echo $proyecto['IDProyecto']; ?>" class="btn btn-danger btn-sm">Borrar</a>
                </div>
            </li>
        <?php endforeach; ?>
    </ul>
<?php else : ?>
    <p>No se encontraron proyectos.</p>
<?php endif; ?>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../../base.php'; ?>

<?php ob_start() ?>
<h3>Gestión-><a class="enlaceVerde" href="index.php?ctl=ProveedoresInicio">Proveedores</a>->Ver</h3>
<hr>
<?php if (!empty($proveedores)) : ?>
    <ul class="list-group">
        <?php foreach ($proveedores as $proveedor) : ?>
            <li class="list-group-item d-flex justify-content-between align-items-center">
                <div>
                    <strong>Nombre:</strong> <?php echo htmlspecialchars($proveedor['Nombre']); ?><br>
                    <strong>Email:</strong> <?php echo htmlspecialchars($proveedor['Email']); ?><br>
                    <strong>Teléfono:</strong> <?php echo htmlspecialchars($proveedor['Telefono']); ?><br>
                    <strong>Dirección:</strong> <?php echo htmlspecialchars($proveedor['Direccion']); ?><br>
                    <strong>Descripción:</strong> <?php echo htmlspecialchars($proveedor['Descripcion']); ?><br>
                </div>
                <div>
                    <a href="index.php?ctl=ProveedoresEditar&id=<?php echo $proveedor['IDProveedor']; ?>" class="btn btn-primary btn-sm">Editar</a>
                    <a href="index.php?ctl=ProveedoresBorrar&id=<?php echo $proveedor['IDProveedor']; ?>" class="btn btn-danger btn-sm">Borrar</a>
                </div>
            </li>
        <?php endforeach; ?>
    </ul>
<?php else : ?>
    <p>No se encontraron proveedores.</p>
<?php endif; ?>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../../base.php'; ?>

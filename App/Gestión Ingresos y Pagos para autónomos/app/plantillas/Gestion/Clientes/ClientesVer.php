<?php ob_start() ?>
<h3>Gestión-><a class="enlaceVerde" href="index.php?ctl=ClientesInicio">Clientes</a>->Ver</h3>
<hr>
<?php if (!empty($clientes)) : ?>
    <ul class="list-group">
        <?php foreach ($clientes as $cliente) : ?>
            <li class="list-group-item d-flex justify-content-between align-items-center">
                <div>
                    <strong>Nombre:</strong> <?php echo htmlspecialchars($cliente['Nombre']); ?><br>
                    <strong>Email:</strong> <?php echo htmlspecialchars($cliente['Email']); ?><br>
                    <strong>Teléfono:</strong> <?php echo htmlspecialchars($cliente['Telefono']); ?><br>
                    <strong>Dirección:</strong> <?php echo htmlspecialchars($cliente['Direccion']); ?><br>
                    <strong>Descripción:</strong> <?php echo htmlspecialchars($cliente['Descripcion']); ?><br>
                </div>
                <div>
                    <a href="index.php?ctl=ClientesEditar&id=<?php echo $cliente['IDCliente']; ?>" class="btn btn-primary btn-sm">Editar</a>
                    <a href="index.php?ctl=ClientesBorrar&id=<?php echo $cliente['IDCliente']; ?>" class="btn btn-danger btn-sm">Borrar</a>
                </div>
            </li>
        <?php endforeach; ?>
    </ul>
<?php else : ?>
    <p>No se encontraron clientes.</p>
<?php endif; ?>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../../base.php'; ?>

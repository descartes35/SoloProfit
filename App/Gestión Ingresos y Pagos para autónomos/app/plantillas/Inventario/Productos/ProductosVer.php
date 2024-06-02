<?php ob_start() ?>
<h3>Inventario-><a class="enlaceVerde" href="index.php?ctl=ProductosInicio">Productos</a>->Ver</h3>
<hr>
<?php if (!empty($productos)) : ?>
    <ul class="list-group">
        <?php foreach ($productos as $producto) : ?>
            <li class="list-group-item d-flex justify-content-between align-items-center">
                <div>
                    <strong>Nombre:</strong> <?php echo htmlspecialchars($producto['Nombre']); ?><br>
                    <strong>Categoría:</strong> <?php echo htmlspecialchars($producto['Categoria']); ?><br>
                    <strong>Precio de Compra:</strong> <?php echo htmlspecialchars($producto['PrecioCompra']); ?><br>
                    <strong>Precio de Venta:</strong> <?php echo htmlspecialchars($producto['PrecioVenta']); ?><br>
                    <strong>Stock:</strong> <?php echo htmlspecialchars($producto['Stock']); ?><br>
                    <strong>Descripción:</strong> <?php echo htmlspecialchars($producto['Descripcion']); ?><br>
                    <strong>Fecha de Registro:</strong> <?php echo htmlspecialchars($producto['FechaRegistro']); ?><br>
                    <strong>Tipo:</strong> <?php echo htmlspecialchars($producto['Tipo']); ?><br>
                </div>
                <div>
                    <a href="index.php?ctl=ProductosEditar&id=<?php echo $producto['IDArticulo']; ?>" class="btn btn-primary btn-sm">Editar</a>
                    <a href="index.php?ctl=ProductosBorrar&id=<?php echo $producto['IDArticulo']; ?>" class="btn btn-danger btn-sm">Borrar</a>
                </div>
            </li>
        <?php endforeach; ?>
    </ul>
<?php else : ?>
    <p>No se encontraron productos.</p>
<?php endif; ?>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../../base.php'; ?>
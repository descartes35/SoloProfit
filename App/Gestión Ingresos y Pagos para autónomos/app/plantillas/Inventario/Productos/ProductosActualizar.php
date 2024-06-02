<?php ob_start() ?>
<h3>Inventario-><a class="enlaceVerde" href="index.php?ctl=ProductosInicio">Productos</a>->Editar</h3>
<hr>
<form method="post" action="index.php?ctl=ProductosEditar&id=<?php echo htmlspecialchars($producto['IDArticulo']); ?>">
    <div class="mb-3">
        <label for="nombre" class="form-label">Nombre</label>
        <input type="text" class="form-control" id="nombre" name="nombre" value="<?php echo htmlspecialchars($producto['Nombre']); ?>" required>
    </div>
    <div class="mb-3">
        <label for="categoria" class="form-label">Categoría</label>
        <input type="text" class="form-control" id="categoria" name="categoria" value="<?php echo htmlspecialchars($producto['Categoria']); ?>" required>
    </div>
    <div class="mb-3">
        <label for="precioCompra" class="form-label">Precio de Compra</label>
        <input type="number" step="0.01" class="form-control" id="precioCompra" name="precioCompra" value="<?php echo htmlspecialchars($producto['PrecioCompra']); ?>" required>
    </div>
    <div class="mb-3">
        <label for="precioVenta" class="form-label">Precio de Venta</label>
        <input type="number" step="0.01" class="form-control" id="precioVenta" name="precioVenta" value="<?php echo htmlspecialchars($producto['PrecioVenta']); ?>" required>
    </div>
    <div class="mb-3">
        <label for="stock" class="form-label">Stock</label>
        <input type="number" class="form-control" id="stock" name="stock" value="<?php echo htmlspecialchars($producto['Stock']); ?>" required>
    </div>
    <div class="mb-3">
        <label for="descripcion" class="form-label">Descripción</label>
        <textarea class="form-control" id="descripcion" name="descripcion" rows="3" required><?php echo htmlspecialchars($producto['Descripcion']); ?></textarea>
    </div>
    <div class="mb-3">
        <label for="fechaRegistro" class="form-label">Fecha de Registro</label>
        <input type="date" class="form-control" id="fechaRegistro" name="fechaRegistro" value="<?php echo htmlspecialchars($producto['FechaRegistro']); ?>" required>
    </div>
    <div class="mb-3">
        <label for="tipo" class="form-label">Tipo</label>
        <input type="text" class="form-control" id="tipo" name="tipo" value="<?php echo htmlspecialchars($producto['Tipo']); ?>" required>
    </div>
    <button type="submit" class="btn btn-primary">Actualizar</button>
</form>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../../base.php'; ?>

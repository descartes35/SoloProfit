<?php ob_start() ?>
<h3>Inventario-><a class="enlaceVerde" href="index.php?ctl=ProductosInicio">Productos</a>->Añadir</h3>
<hr>
<form class="row g-3" method="post">
    <div class="col-md-6">
        <label for="Nombre" class="form-label">Nombre:</label>
        <input type="text" class="form-control" id="Nombre" name="Nombre" required>
    </div>
    <div class="col-md-6">
        <label for="Categoria" class="form-label">Categoría:</label>
        <input type="text" class="form-control" id="Categoria" name="Categoria" required>
    </div>
    <div class="col-md-6">
        <label for="PrecioCompra" class="form-label">Precio de Compra:</label>
        <input type="number" step="0.01" class="form-control" id="PrecioCompra" name="PrecioCompra" required>
    </div>
    <div class="col-md-6">
        <label for="PrecioVenta" class="form-label">Precio de Venta:</label>
        <input type="number" step="0.01" class="form-control" id="PrecioVenta" name="PrecioVenta" required>
    </div>
    <div class="col-md-6">
        <label for="Stock" class="form-label">Stock:</label>
        <input type="number" class="form-control" id="Stock" name="Stock" required>
    </div>
    <div class="col-md-6">
        <label for="Descripcion" class="form-label">Descripción:</label>
        <textarea class="form-control" id="Descripcion" name="Descripcion" rows="3" required></textarea>
    </div>
    <div class="col-md-6">
        <label for="Tipo" class="form-label">Tipo:</label>
        <input type="text" class="form-control" id="Tipo" name="Tipo" value="Producto" disabled>
    </div>
    <div class="col-12 text-center">
        <br>
        <button type="submit" class="btn btn-warning">Añadir producto</button>
    </div>
</form>
<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../../base.php'; ?>

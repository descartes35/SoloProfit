<?php ob_start() ?>
<h3 class="text-center mt-5">Análisis financiero</h3>
<hr>

<div class="container mt-5">
    <div class="row">
        <div class="col-md-6">
            <h4 class="h3Resumen">Ingresos</h4>
            <div class="table-responsive">
                <table class="table table-striped table-hover">
                    <thead>
                        <tr>
                            <th>Nombre</th>
                            <th>Apellidos</th>
                            <th>Total Ingresos</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php foreach ($ingresosPorUsuario as $ingreso) : ?>
                            <tr>
                                <td><?php echo $ingreso['Nombre']; ?></td>
                                <td><?php echo $ingreso['Apellidos']; ?></td>
                                <td><?php echo $ingreso['TotalIngresos']; ?></td>
                            </tr>
                        <?php endforeach; ?>
                    </tbody>
                </table>
            </div>
        </div>
        <div class="col-md-6">
            <h4 class="h3Resumen">Gastos</h4>
            <div class="table-responsive">
                <table class="table table-striped table-hover">
                    <thead>
                        <tr>
                            <th>Nombre</th>
                            <th>Apellidos</th>
                            <th>Total Gastos</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php foreach ($gastosPorUsuario as $gasto) : ?>
                            <tr>
                                <td><?php echo $gasto['Nombre']; ?></td>
                                <td><?php echo $gasto['Apellidos']; ?></td>
                                <td><?php echo $gasto['TotalGastos']; ?></td>
                            </tr>
                        <?php endforeach; ?>
                    </tbody>
                </table>
            </div>
        </div>
    </div>

    <div class="row mt-5">
        <div class="col-md-6">
            <h4 class="h3Resumen">Balance Financiero</h4>
            <div class="table-responsive">
                <table class="table table-striped table-hover">
                    <thead>
                        <tr>
                            <th>Nombre</th>
                            <th>Apellidos</th>
                            <th>Total Ingresos</th>
                            <th>Total Gastos</th>
                            <th>Balance</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php foreach ($balanceFinanciero as $balance) : ?>
                            <tr>
                                <td><?php echo $balance['Nombre']; ?></td>
                                <td><?php echo $balance['Apellidos']; ?></td>
                                <td><?php echo $balance['TotalIngresos']; ?></td>
                                <td><?php echo $balance['TotalGastos']; ?></td>
                                <td><?php echo $balance['Balance']; ?></td>
                            </tr>
                        <?php endforeach; ?>
                    </tbody>
                </table>
            </div>
        </div>
    </div>

    <div class="row mt-5">
        <div class="col-md-6">
            <h4 class="h3Resumen">Ingresos por Categoría</h4>
            <div class="table-responsive">
                <table class="table table-striped table-hover">
                    <thead>
                        <tr>
                            <th>Categoría</th>
                            <th>Total Ingresos</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php foreach ($ingresosPorCategoria as $ingreso) : ?>
                            <tr>
                                <td><?php echo $ingreso['Categoria']; ?></td>
                                <td><?php echo $ingreso['TotalIngresos']; ?></td>
                            </tr>
                        <?php endforeach; ?>
                    </tbody>
                </table>
            </div>
        </div>
        <div class="col-md-6">
            <h4 class="h3Resumen">Gastos por Categoría</h4>
            <div class="table-responsive">
                <table class="table table-striped table-hover">
                    <thead>
                        <tr>
                            <th>Categoría</th>
                            <th>Total Gastos</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php foreach ($gastosPorCategoria as $gasto) : ?>
                            <tr>
                                <td><?php echo $gasto['Categoria']; ?></td>
                                <td><?php echo $gasto['TotalGastos']; ?></td>
                            </tr>
                        <?php endforeach; ?>
                    </tbody>
                </table>
            </div>
        </div>
    </div>

    <div class="row mt-5">
        <div class="col-md-6">
            <h4 class="h3Resumen">Ingresos por Mes</h4>
            <div class="table-responsive">
                <table class="table table-striped table-hover">
                    <thead>
                        <tr>
                            <th>Año</th>
                            <th>Mes</th>
                            <th>Total Ingresos</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php foreach ($ingresosPorMes as $ingreso) : ?>
                            <tr>
                                <td><?php echo $ingreso['Año']; ?></td>
                                <td><?php echo $ingreso['Mes']; ?></td>
                                <td><?php echo $ingreso['TotalIngresos']; ?></td>
                            </tr>
                        <?php endforeach; ?>
                    </tbody>
                </table>
            </div>
        </div>
        <div class="col-md-6">
            <h4 class="h3Resumen">Gastos por Mes</h4>
            <div class="table-responsive">
                <table class="table table-striped table-hover">
                    <thead>
                        <tr>
                            <th>Año</th>
                            <th>Mes</th>
                            <th>Total Gastos</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php foreach ($gastosPorMes as $gasto) : ?>
                            <tr>
                                <td><?php echo $gasto['Año']; ?></td>
                                <td><?php echo $gasto['Mes']; ?></td>
                                <td><?php echo $gasto['TotalGastos']; ?></td>
                            </tr>
                        <?php endforeach; ?>
                    </tbody>
                </table>
            </div>
        </div>
    </div>
</div>

<?php $contenido = ob_get_clean(); ?>
<?php include_once __DIR__ . '/../../base.php'; ?>
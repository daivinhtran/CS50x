<form action= "sell.php" method="post">
    <div class="form-group">
      <label for="sel1">Select stock to sell:</label>
      <select class="form-control" id="sel1" name = "stocksell">
      <?php foreach($positions as $position): ?>
        <option><?= $position["symbol"] ?></option>
      <?php endforeach ?>
      </select>
    </div>
    <div class = "form-group">
        <button type = "submit" class="btn btn-default">Sell</button>
    </div>
 </form>

 <div>
    or <a href="index.php">Portfolio</a>
</div>


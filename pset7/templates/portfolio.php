<ul class="nav nav-pills nav-justified">
    <li><a href="quote.php">Quote</a></li>
    <li><a href="buy.php">Buy</a></li>
    <li><a href="presell.php">Sell</a></li>
    <li><a href="prehistory.php">History</a></li>
    <li><a href="deposit.php">Deposit</a></li>
    <li><a href="logout.php"><strong>Log Out</strong></a></li>
</ul>
<table  class="table table-striped">
	<thead>
	  <tr>
	    <th>Stock Name</th>
	    <th>Stock Symbol</th> 
	    <th>Shares</th>
	    <th>Price</th>
	    <th>Value</th>
	  </tr>
	 </thead>
	 <tbody>
	 		 <tr style = "text-align: left">
		    	<td><strong>CASH</strong></td> 
		        <td></td> 
		        <td></td> 
		        <td></td> 
		        <td><?= $cash ?></td> 
		    </tr>
		<?php foreach ($positions as $position): ?>

		    <tr style = "text-align: left">
		    	<td><?= $position["name"] ?></td> 
		        <td><?= $position["symbol"] ?></td> 
		        <td><?= $position["shares"] ?></td> 
		        <td><?= $position["price"] ?></td> 
		        <td><?= $position["value"] ?></td> 
		    </tr>
		<?php endforeach ?>
	</tbody>
</table>




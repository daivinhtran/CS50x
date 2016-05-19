<table  class="table table-striped">
	<thead>
	  <tr>
	    <th>Action</th>
	    <th>Stock Symbol</th> 
	    <th>Shares</th> 
	    <th>Price</th> 
	    <th>Time</th> 
	  </tr>
	 </thead>
	 <tbody>
		<?php foreach ($positions as $position): ?>
		    <tr style = "text-align: left">
		    	<td><?= $position["action"] ?></td> 
		        <td><?= $position["symbol"] ?></td> 
		        <td><?= $position["shares"] ?></td> 
		       	<td><?= $position["price"] ?></td> 
		       	<td><?= $position["time"] ?></td> 
		    </tr>
		<?php endforeach ?>
	</tbody>
</table>

<div>
    <a href="clearhistory.php">Clear History</a>
</div>

<div>
    or <a href="index.php">Portfolio</a>
</div>






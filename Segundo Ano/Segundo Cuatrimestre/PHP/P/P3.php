<!DOCTYPE html>
<html>
<head>

</head>
<body>

<table>
	<?php
	
	$I = 0;
	
	for ($J = 1; $J <= 15; $J++){ ?>
		
		<tr>

		<?php for($K = 1; $K <= 5; $K++){ 
			
			if($K <> 3){ ?>
				<td>
					 <div style='border:1px solid black; width:50px; height:50px; text-align:center; line-height:50px;'><?= $I++ ?></div> 
				</td>
			<?php } 
			
			else { ?>
				
				<td>
					<div style= 'margin-right:50px;'> </div>
				</td>
			
			<?php } ?>
		
		<?php } ?>
				
		</tr>
	<?php } ?>
	
	</table>


</body>
</html>
<!DOCTYPE html>
<html>
<head>

</head>
<body>

<table>
	<?php
	$I = 1;
	for ($J = 1; $J <= 15; $J++){ ?>
		<tr>
		<?="
			<td>
				<div style='border:1px solid black; width:50px; height:50px; text-align:center; line-height:50px;'>".$I++."</div>
			</td>
			<td>
				<div style='border:1px solid black; width:50px; height:50px; text-align:center; line-height:50px;'>".$I++."</div>
			</td>

			<td>
				<div style= 'margin-right:50px;'> </div>
			</td>

			<td>
				<div style='border:1px solid black; width:50px; height:50px; text-align:center; line-height:50px;'>".$I++."</div>
			</td>
			<td>
				<div style='border:1px solid black; width:50px; height:50px; text-align:center; line-height:50px;'>".$I++."</div>
			</td> 
		"?>
		
		</tr>
	<?php } ?>
	</table>


</body>
</html>
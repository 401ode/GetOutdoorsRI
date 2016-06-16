<?php
/**
 * @file views-view-summary-unformatted--classification_specification.tpl.php
 * Displays alphabetical and 'ALL' links for a views 'glossary' view.
 * Reference: http://drupal.org/node/403012
 *
 */
?>
<?php
	$total = 0;
	$letters = range('A', 'Z');

	foreach($rows as $id => $row){
		$existing_letters[] = $row->link;
		$row->url = preg_replace('/[\w]*=&/' , '' , $row->url); 
		$row->url = preg_replace('/&[\w]*=$/' , '' , $row->url);
		$row->url = preg_replace('/\?$/' , '' , $row->url);
		$urls[$row->link] = strtolower($row->url);
		$counts[$row->link] = $row->count;
		$total += $row->count;
		
		$separator = (!empty($row->separator) ? $row->separator : ' | ');
		if(!empty($row_classes[$id])) { 
			$classes[$row->link] = $row_classes[$id]; 
		}
		if(!empty($options['count'])) { 
			$show_count = $options['count'];
		}
	}
	
	$letters[] = 'ALL';
	$existing_letters[] = 'ALL';

	$url_query = explode('?', $rows[0]->url);

	$urls['ALL'] = substr_replace(strtolower($url_query[0]), 'all', -1, strlen($rows[0]->link));
	unset ($url_query[0]);
	if (isset($url_query)) { 
		$urls['ALL'] .= '?' . implode('?', $url_query); 
	}
	$counts['ALL'] = $total;

	print '<div class="views-summary views-summary-unformatted">';
	
	foreach($letters as $letter){
		if(in_array($letter, $existing_letters)){

			$build_nav = '<span class="result"><a href=' . $urls[$letter];
			if (isset($classes[$letter])) {
				$build_nav .= ' class="' . $classes[$letter] . '"';
			}
			$build_nav .= '>' . $letter . '</a>';
			if (isset($show_count)) {
				$build_nav .= '</span><span class="count">(' . $counts[$letter]. ')</span>';
			}
			
			$nav[] = $build_nav;
		}
		else {
			$nav[] = '<span class="no-result">' . $letter . '</span>';
		}
	}
	
	print implode($separator, $nav);
	print '</div>';
?>
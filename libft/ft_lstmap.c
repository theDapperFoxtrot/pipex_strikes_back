/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:00:33 by smishos           #+#    #+#             */
/*   Updated: 2024/04/27 16:22:41 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	new_list = NULL;
	new_node = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new_content = f(lst->content);
		// 	 if (!new_content)
		//  {
		// 	ft_lstclear(&new_list, del);
		// 	return (NULL);
		//  }
		new_node = ft_lstnew(new_content);
		if (new_node == NULL)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}


// The commented-out section of code seems to handle a case where the result of applying the transformation function (f) to an element of the linked list produces a NULL value. Depending on the specific requirements of your application, you may or may not want to handle this case.

// Here are some circumstances where handling NULL content might be necessary:

// Error Handling: If the transformation function (f) encounters an error or invalid input for certain elements in the linked list, it may return NULL. In such cases, it's essential to handle this scenario gracefully to avoid unexpected behavior or crashes.
// Memory Management: If the transformation function allocates memory dynamically and returns NULL to indicate a failure in memory allocation, it's crucial to handle this situation properly to prevent memory leaks.
// Data Validation: Depending on the nature of the data and the transformation function, NULL content might not be acceptable in the resulting linked list. In such cases, you may want to skip or discard elements that result in NULL content.
// Function Semantics: In some cases, the transformation function may have specific semantics that dictate the handling of NULL content. For example, it might indicate a special case or an error condition that needs to be dealt with appropriately.
// In summary, handling NULL content depends on the specific requirements and constraints of your application. If NULL content is possible and needs to be handled in a particular way, you should uncomment and customize the relevant section of the code accordingly.

// If the function you're passing as the transformation function (f) is malloc(), you might not necessarily need the commented-out section to handle NULL content. Here's why:

// malloc() Behavior: The malloc() function allocates memory dynamically, and it returns a pointer to the allocated memory block. It typically returns NULL only if it fails to allocate memory due to insufficient memory available.
// Expected Behavior: In most cases, when you're using malloc() as the transformation function, you expect it to successfully allocate memory for the content of each node. If it fails to allocate memory, it likely indicates a critical error condition that might make further execution of the program problematic.
// Memory Allocation Failure: If malloc() fails to allocate memory, it's usually a serious problem, and simply skipping or discarding the element that resulted in a NULL content might not be sufficient. In such cases, it's often better to handle the failure gracefully at a higher level of abstraction, such as by terminating the program or reporting an error.
// Memory Management: If malloc() fails, it's essential to handle this situation properly to prevent memory leaks and ensure the stability of your program. In many cases, this involves cleaning up any allocated memory and properly terminating the program or returning an error code.
// Given these points, if you're using malloc() as the transformation function, you may not require the commented-out section specifically to handle NULL content. However, you should still ensure that your program handles memory allocation failures appropriately to maintain robustness and reliability.

// Your code appears to handle memory allocation failures appropriately to maintain robustness and reliability. Here's why:

// Checking for NULL Parameters: Your function checks if lst or f is NULL. If either of them is NULL, it returns NULL immediately, indicating that the function cannot proceed without valid input parameters. This is a good practice to ensure that the function doesn't operate on invalid data.
// Memory Allocation: Inside the loop, you allocate memory for the new_content and new_node variables. You also allocate memory for the content of each new node using f(lst->content). If any of these allocations fail (i.e., if malloc() returns NULL), your code properly handles the failure by cleaning up allocated memory and returning NULL. This prevents memory leaks and ensures that your program doesn't proceed with incomplete data structures.
// Cleanup on Failure: In case of a memory allocation failure when creating a new node (new_node == NULL), your code calls the deletion function del on new_content to release any resources associated with the content. It then clears the entire new_list using ft_lstclear to free the memory allocated for the nodes that were successfully created before the failure occurred. This cleanup ensures that your program doesn't leave behind dangling pointers or memory leaks.
// Returning NULL: If any memory allocation fails or if the input parameters are invalid, your function returns NULL. This allows the caller of the function to detect and handle the failure appropriately.
// Overall, your code demonstrates good practices for handling memory allocation failures and maintaining robustness and reliability. However, it's always a good idea to thoroughly test your code, especially under conditions where memory may be constrained, to ensure that it behaves as expected in all scenarios.
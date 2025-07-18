const SCROLL_THRESHOLD = 200;

function initScrollToTop() {
	const button = document.getElementById('scrollToTopBtn');
	if (!button) return;

	window.addEventListener('scroll', () => {
		if (window.scrollY > SCROLL_THRESHOLD) {
			button.classList.add('visible');
		} else {
			button.classList.remove('visible');
		}
	});

	button.addEventListener('click', () => {
		window.scrollTo({
			top: 0,
			behavior: 'smooth'
		});
	});
}

function initScrollEvent() {
	const navLinks = document.querySelectorAll('.navigation__link[href^="#"]');

	navLinks.forEach(link => {
		link.addEventListener('click', (e) => {
			e.preventDefault();
			const targetId = link.getAttribute('href');
			const targetElement = document.querySelector(targetId);

			if (targetElement) {
				targetElement.scrollIntoView({
					behavior: 'smooth'
				});
			}
		});
	});
}

document.addEventListener('DOMContentLoaded', () => {
	const navLinks = document.querySelectorAll('.navigation__link');

	initScrollToTop();
	initScrollEvent();

	navLinks.forEach(link => {
		link.addEventListener('click', function () {
			setTimeout(() => {
				this.blur();
			}, 300);
		});
	});
});


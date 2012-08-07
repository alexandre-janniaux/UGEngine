//#include <SFML/Graphics.hpp>

#include <UGEngine/EntityComponents/Entity.hpp>
#include <UGEngine/ExempleComponents/HealthComponent.hpp>
#include <UGEngine/MessageComponents/DamageMessage.hpp>
#include <iostream>
#include <cstdlib>

int main (int argc, char** argv) 
{
	/*
    sf::RenderWindow window ( sf::VideoMode(800,600), "Example application : entity component system" );
    sf::Event event;
    
    sf::Font font;
    font.loadFromFile("anyfont.ttf")
    sf::Text helpText ("Entity component system", font);
    
/*

Entity entity ( "entity_name" ,XmlEntiyProvider ( FileProvider( "resource_type", "resource_name.xml" ) ) );
comp = SPhysicEntityManager->getPhysicComponentFromEntityName("entity_name");
comp.impulse(0,5.f, 0);
*/
	uge::Entity entity("my_entity");
	uge::Entity entity2("other_entity");
	
	uge::components::Health health(entity, 100);	
	uge::components::Health health2(entity2, 100);	

	entity.addComponent<uge::HealMessage> (health);
	entity.addComponent<uge::DamageMessage> (health);

	entity2.addComponent<uge::HealMessage> (health2);
	entity2.addComponent<uge::DamageMessage> (health2);

	std::cout << "Entity life is " << health.getHealth() << std::endl;
	std::cout << "Ah, entity received an attack" << std::endl;
	entity.broadcast<uge::DamageMessage>(entity2,10);
	std::cout << "Entity life is " << health.getHealth() << std::endl;
	

/*
	while (window.isOpen())
	{
	    while (window.pollEvent(event))
	    {
	        if (event.type == sf:::Event::Closed)
	            window.close();
	    }
	    
	    window.clear();
	    
	    //rendu
	    
	    window.display();
	
	}
*/
	return EXIT_SUCCESS;
}

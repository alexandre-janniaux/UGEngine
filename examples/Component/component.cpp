//#include <SFML/Graphics.hpp>

#include <UGEngine/Entity/Core/Entity.hpp>
#include <UGEngine/Entity/Component/Health.hpp>
#include <UGEngine/Entity/Message/Damage.hpp>
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
	
	uge::component::Health<uge::Uint32> health(entity, 100);	
	uge::component::Health<uge::Uint32> health2(entity2, 100);	

	entity.bind<uge::HealMessage<uge::Uint32>> (health);
	entity.bind<uge::DamageMessage<uge::Uint32>> (health);

	entity2.bind<uge::HealMessage<uge::Uint32>> (health2);
	entity2.bind<uge::DamageMessage<uge::Uint32>> (health2);

	std::cout << "Entity life is " << health.getHealth() << std::endl;
	std::cout << "Ah, entity received an attack" << std::endl;

	uge::DamageMessage<uge::Uint32> attack(10);
	entity.broadcast(attack);
	std::cout << "Entity life is " << health.getHealth() << std::endl;
	

/*
	while (window.isOpen())
	{
	    while (window.pollEvent(event))
	    {
	        if (event.type == sf::Event::Closed)
	            window.close();
	    }
	    
	    window.clear();
	    
	    //rendu
	    
	    window.display();
	
	}
*/
	return EXIT_SUCCESS;
}

#ifndef COLLECTION_H
#define COLLECTION_H

#include<stdio.h>
#include<types.h>
#include<Serializer.h>

namespace TESTAPPLICATION{



template<class T> class Collection
{
	public:

		Collection() 
		{
			Init();
		}

		~Collection() 
		{
			CleanUp();
		}
		
		void Init()
		{
			mSerializer = NULL;
		}

		void CleanUp() {
			mSerializer=NULL;			
			while ( mItem.next ) {
				Pop();
			}
		}
		
		void Push(T* object)
		{
			struct Item *item;
			
			item = new struct Item;
			item->next = mItem.next;
			item->object = object;
			mItem.next = item;

		}

		void Pop()
		{
			if(mItem.next)
			{
				struct Item* prev = mItem.next;
				mItem.next = prev->next;

				delete prev;
				prev = NULL;
			}
		}

		void ListItems()
		{
			struct Item *item;
		
			for ( item=mItem.next; item; item=item->next ) 
			{
				printf("%d,%d,%d,%d\n",item->object->X(),item->object->Y(),item->object->W(),item->object->H());
			}

		}
	
		void SetSerializer(Serializer* serializer)
		{
			mSerializer = serializer;
		}

		void Serialize()
		{
			if(mSerializer==NULL)
			{
				printf("\nSerializer not set. Please set a serializer for this collection before serializing the data.\n");
				return;
			}
			mSerializer->PrintToConsole(SerializableData());
		}

		CollectionData SerializableData()
		{
			struct Item *item;
			mCollectionData.clear();
			for ( item=mItem.next; item; item=item->next ) 
			{
				mCollectionData.push_back(item->object->getObjectData());
			}
			return mCollectionData;
		}


	private:
		struct Item
		{
			~Item()
			{
				delete object;
				object = NULL;
			}
			T* object;
			struct Item* next;
		}mItem;
		CollectionData mCollectionData;
		Serializer* mSerializer;


};
}

#endif

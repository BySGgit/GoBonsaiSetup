void __thiscall Concurrency::propagator_block<Concurrency::single_link_registry<Concurrency::ITarget<unsigned int>>,Concurrency::multi_link_registry<Concurrency::ISource<enum Concurrency::agent_status>>,Concurrency::ordered_message_processor<unsigned int>>::decline_incoming_messages(
        _BYTE *this)
{
  *(this + 236) = 1;
}
